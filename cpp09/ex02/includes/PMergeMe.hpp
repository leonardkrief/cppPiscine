#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <algorithm>
# include <iterator>

template<typename RandomAccessIterator, typename Compare>
void merge_insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare compare);

////////////////////////////////////////////////////////////
// Iterator used to sort views of the collection
template<typename Iterator>
class group_iterator
{
    private:
        Iterator _it;
        std::size_t _size;

    public:
        ////////////////////////////////////////////////////////////
        // Public types
        typedef std::random_access_iterator_tag iterator_category;
        typedef Iterator iterator_type;
        typedef typename std::iterator_traits<Iterator>::value_type value_type;
        typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename std::iterator_traits<Iterator>::pointer pointer;
        typedef typename std::iterator_traits<Iterator>::reference reference;

        ////////////////////////////////////////////////////////////
        // Constructors
        group_iterator()
        {};

        group_iterator(Iterator it, std::size_t size):
            _it(it),
            _size(size)
        {};

        ////////////////////////////////////////////////////////////
        // Members access
        iterator_type base() const
        {
            return _it;
        }

        std::size_t size() const
        {
            return _size;
        }

        ////////////////////////////////////////////////////////////
        // Element access

        reference operator*() const
        {
            return _it[_size - 1];
        }

        pointer operator->() const
        {
            return &(operator*());
        }

        ////////////////////////////////////////////////////////////
        // Increment/decrement operators

        group_iterator& operator++()
        {
            _it += _size;
            return *this;
        }

        group_iterator operator++(int)
        {
            group_iterator tmp = *this;
            operator++();
            return tmp;
        }

        group_iterator& operator--()
        {
            _it -= _size;
            return *this;
        }

        group_iterator operator--(int)
        {
            group_iterator tmp = *this;
            operator--();
            return tmp;
        }

        group_iterator& operator+=(std::size_t increment)
        {
            _it += _size * increment;
            return *this;
        }

        group_iterator& operator-=(std::size_t increment)
        {
            _it -= _size * increment;
            return *this;
        }

        ////////////////////////////////////////////////////////////
        // Elements access operators

        typename std::iterator_traits<Iterator>::reference operator[](std::size_t pos)
        {
            return _it[pos * _size + _size - 1];
        }

        typename std::iterator_traits<Iterator>::reference operator[](std::size_t pos) const
        {
            return _it[pos * _size + _size - 1];
        }
};

template<typename Iterator1, typename Iterator2>
void iter_swap(group_iterator<Iterator1> lhs, group_iterator<Iterator2> rhs)
{
    std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}

////////////////////////////////////////////////////////////
// Comparison operators

template<typename Iterator1, typename Iterator2>
bool operator==(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() == rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator!=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() != rhs.base();
}

////////////////////////////////////////////////////////////
// Relational operators

template<typename Iterator1, typename Iterator2>
bool operator<(const group_iterator<Iterator1>& lhs,
               const group_iterator<Iterator2>& rhs)
{
    return lhs.base() < rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator<=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() <= rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator>(const group_iterator<Iterator1>& lhs,
               const group_iterator<Iterator2>& rhs)
{
    return lhs.base() > rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator>=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base >= rhs.base();
}

////////////////////////////////////////////////////////////
// Arithmetic operators

template<typename Iterator>
group_iterator<Iterator> operator+(group_iterator<Iterator> it, std::size_t size)
{
    return it += size;
}

template<typename Iterator>
group_iterator<Iterator> operator+(std::size_t size, group_iterator<Iterator> it)
{
    return it += size;
}

template<typename Iterator>
group_iterator<Iterator> operator-(group_iterator<Iterator> it, std::size_t size)
{
    return it -= size;
}

template<typename Iterator>
typename group_iterator<Iterator>::difference_type operator-(const group_iterator<Iterator>& lhs, const group_iterator<Iterator>& rhs)
{
    return (lhs.base() - rhs.base()) / lhs.size();
}

////////////////////////////////////////////////////////////
// Construction function

template<typename Iterator>
group_iterator<Iterator> make_group_iterator(Iterator it, std::size_t size)
{
    group_iterator<Iterator>(it, size);
}

template<typename Iterator>
group_iterator<Iterator> make_group_iterator(group_iterator<Iterator> it, std::size_t size)
{
    group_iterator<Iterator>(it.base(), size * it.size());
}

////////////////////////////////////////////////////////////
// Merge-insertion sort

// Small node struct for pend elements
template<
    typename RandomAccessIterator,
    typename Compare
>
struct node
{
    RandomAccessIterator it;
    typename std::list<RandomAccessIterator>::iterator next;
};

template<
    typename RandomAccessIterator,
    typename Compare
>
void merge_insertion_sort_impl(RandomAccessIterator first, RandomAccessIterator last,
                               Compare compare)
{
    // Cache all the differences between a Jacobsthal number and its
    // predecessor that fit in 64 bits, starting with the difference
    // between the Jacobsthal numbers 4 and 3 (the previous ones are
    // unneeded)
    static const unsigned long long jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };

    using std::iter_swap;

    typename std::iterator_traits<RandomAccessIterator>::difference_type size = std::distance(first, last);
    if (size < 2) return;

    // Whether there is a stray element not in a pair
    // at the end of the chain
    bool has_stray = (size % 2 != 0);

    ////////////////////////////////////////////////////////////
    // Group elements by pairs

    RandomAccessIterator end = has_stray ? last - 1 : last;
    for (RandomAccessIterator it = first ; it != end ; it += 2)
    {
        if (compare(it[1], it[0]))
        {
            iter_swap(it, it + 1);
        }
    }

    ////////////////////////////////////////////////////////////
    // Recursively sort the pairs by max

    merge_insertion_sort(
        make_group_iterator(first, 2),
        make_group_iterator(end, 2),
        compare
    );

    ////////////////////////////////////////////////////////////
    // Separate main chain and pend elements


    // The first pend element is always part of the main chain,
    // so we can safely initialize the list with the first two
    // elements of the sequence
    std::list<RandomAccessIterator> chain;
    chain.push_back(first);
    chain.push_back(first + 1);
    std::list<node<RandomAccessIterator, Compare> > pend;

    for (RandomAccessIterator it = first + 2 ; it != end ; it += 2)
    {
        typename std::list<RandomAccessIterator>::iterator tmp = chain.insert(chain.end(), it + 1);
        pend.push_back(node<RandomAccessIterator, Compare>(it, tmp));
    }

    // Add the last element to pend if it exists, when it
    // exists, it always has to be inserted in the full chain,
    // so giving it chain.end() as end insertion point is ok
    if (has_stray)
    {
        pend.push_back(node<RandomAccessIterator, Compare>(end, chain.end()));
    }

    ////////////////////////////////////////////////////////////
    // Binary insertion into the main chain

    for (int k = 0 ; ; ++k)
    {
        // Find next index
        typename std::list<node<RandomAccessIterator, Compare> >::iterator it;
        std::size_t dist = static_cast<std::size_t>(jacobsthal_diff[k]);
        if (dist >= pend.size()) break;
        it = pend.begin();
        std::advance(it, dist);

        while (true)
        {
            struct CompareWrapper {
                CompareWrapper(Compare comp) : comp(comp) {}
                bool operator()(RandomAccessIterator lhs, RandomAccessIterator rhs) {
                    return comp(*lhs, *rhs);
                }
                Compare comp;
            };

            CompareWrapper comp_wrapper(compare);
            typename std::list<RandomAccessIterator>::iterator insertion_point = std::upper_bound(
                chain.begin(), it->next, it->it, comp_wrapper
            );
            chain.insert(insertion_point, it->it);

            it = pend.erase(it);
            if (it == pend.begin()) break;
            --it;
        }
    }

    // If there are elements left, insert them too
    while (!pend.empty())
    {
        typename std::list<node<RandomAccessIterator, Compare> >::iterator it = pend.end();
        --it; // replace std::prev() with manual decrement

        // Similar replacement for lambda as above
        struct CompareWrapper {
            CompareWrapper(Compare comp) : comp(comp) {}
            bool operator()(RandomAccessIterator lhs, RandomAccessIterator rhs) {
                return comp(*lhs, *rhs);
            }
            Compare comp;
        };

        CompareWrapper comp_wrapper(compare);

        typename std::list<RandomAccessIterator>::iterator insertion_point = std::upper_bound(
            chain.begin(), it->next, it->it, comp_wrapper
        );
        chain.insert(insertion_point, it->it);
        pend.pop_back();
    }

    ////////////////////////////////////////////////////////////
    // Move values in order to a cache then back to origin

    std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> cache;
    cache.reserve(size);

    for (typename std::list<RandomAccessIterator>::iterator it = chain.begin(); it != chain.end(); ++it)
    {
        RandomAccessIterator begin = *it;
        RandomAccessIterator end = begin + 2;
        std::copy(begin, end, std::back_inserter(cache));
    }
    std::copy(cache.begin(), cache.end(), first);
}

template<typename RandomAccessIterator>
void merge_insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    merge_insertion_sort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

template<
    typename RandomAccessIterator,
    typename Compare
>
void merge_insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare compare)
{
    merge_insertion_sort_impl(
        make_group_iterator(first, 1),
        make_group_iterator(last, 1),
        compare
    );
}

#endif