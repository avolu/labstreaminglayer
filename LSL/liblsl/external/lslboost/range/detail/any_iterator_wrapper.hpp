// Boost.Range library
//
//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.lslboost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.lslboost.org/libs/range/
//
#ifndef BOOST_RANGE_DETAIL_ANY_ITERATOR_WRAPPER_HPP_INCLUDED
#define BOOST_RANGE_DETAIL_ANY_ITERATOR_WRAPPER_HPP_INCLUDED

#include <lslboost/range/config.hpp>
#include <lslboost/range/detail/any_iterator_interface.hpp>

namespace lslboost
{
    namespace range_detail
    {
        template<
            class WrappedIterator
          , class Reference
          , class Buffer
        >
        class any_incrementable_iterator_wrapper
            : public any_incrementable_iterator_interface<
                        Reference
                      , Buffer
                    >
        {
            BOOST_RANGE_CONCEPT_ASSERT(( IncrementableIteratorConcept<WrappedIterator> ));
        public:
            typedef WrappedIterator wrapped_type;

            BOOST_STATIC_ASSERT(( is_convertible<
                                    typename iterator_reference<WrappedIterator>::type
                                  , Reference
                                  >::value ));

            any_incrementable_iterator_wrapper()
                : m_it()
            {}

            explicit any_incrementable_iterator_wrapper(wrapped_type it)
                : m_it(it)
            {}

        // any_incrementable_iterator implementation
            virtual any_incrementable_iterator_wrapper* clone(
                typename any_incrementable_iterator_wrapper::buffer_type& buffer
                ) const
            {
                return new (buffer.allocate(sizeof(*this)))
                                any_incrementable_iterator_wrapper(m_it);
            }

            virtual any_incrementable_iterator_wrapper<
                        WrappedIterator
                      , typename any_incrementable_iterator_wrapper::const_reference
                      , Buffer
                    >* clone_const_ref(
                        typename any_incrementable_iterator_wrapper::buffer_type& buffer
                ) const
            {
                typedef any_incrementable_iterator_wrapper<
                            WrappedIterator
                          , typename any_incrementable_iterator_wrapper::const_reference
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual any_incrementable_iterator_wrapper<
                        WrappedIterator
                      , typename any_incrementable_iterator_wrapper::reference_as_value_type
                      , Buffer
                    >* clone_reference_as_value(
                        typename any_incrementable_iterator_wrapper::buffer_type& buffer
                ) const
            {
                typedef any_incrementable_iterator_wrapper<
                            WrappedIterator
                          , typename any_incrementable_iterator_wrapper::reference_as_value_type
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual void increment()
            {
                ++m_it;
            }

         private:
            wrapped_type m_it;
        };

        template<
            class WrappedIterator
          , class Reference
          , class Buffer
        >
        class any_single_pass_iterator_wrapper
            : public any_single_pass_iterator_interface<
                        Reference
                      , Buffer
                    >
        {
            struct disabler {};
            BOOST_RANGE_CONCEPT_ASSERT(( SinglePassIteratorConcept<WrappedIterator> ));
        public:

            any_single_pass_iterator_wrapper()
                : m_it()
            {}

            explicit any_single_pass_iterator_wrapper(const WrappedIterator& it)
                : m_it(it)
            {}
        // any_single_pass_iterator_interface<Reference> implementation
            virtual any_single_pass_iterator_wrapper* clone(
                typename any_single_pass_iterator_wrapper::buffer_type& buffer
                ) const
            {
                return new (buffer.allocate(sizeof(*this)))
                            any_single_pass_iterator_wrapper(m_it);
            }

            virtual any_single_pass_iterator_wrapper<
                WrappedIterator
              , typename any_single_pass_iterator_wrapper::const_reference
              , Buffer
            >* clone_const_ref(
                   typename any_single_pass_iterator_wrapper::buffer_type& buffer
                   ) const
            {
                typedef any_single_pass_iterator_wrapper<
                            WrappedIterator
                          , typename any_single_pass_iterator_wrapper::const_reference
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual any_single_pass_iterator_wrapper<
                WrappedIterator
              , typename any_single_pass_iterator_wrapper::reference_as_value_type
              , Buffer
            >* clone_reference_as_value(
                typename any_single_pass_iterator_wrapper::buffer_type& buffer
                ) const
            {
                typedef any_single_pass_iterator_wrapper<
                            WrappedIterator
                          , typename any_single_pass_iterator_wrapper::reference_as_value_type
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual void increment()
            {
                ++m_it;
            }

            virtual bool equal(const any_single_pass_iterator_interface<Reference, Buffer>& other) const
            {
                return m_it == lslboost::polymorphic_downcast<const any_single_pass_iterator_wrapper*>(&other)->m_it;
            }

            virtual Reference dereference() const
            {
                return *m_it;
            }

        private:
            WrappedIterator m_it;
        };

        template<
            class WrappedIterator
          , class Reference
          , class Buffer
        >
        class any_forward_iterator_wrapper
            : public any_forward_iterator_interface<
                        Reference
                      , Buffer
                    >
        {
            BOOST_RANGE_CONCEPT_ASSERT(( ForwardIteratorConcept<WrappedIterator> ));
        public:
            any_forward_iterator_wrapper()
                : m_it()
            {}

            explicit any_forward_iterator_wrapper(const WrappedIterator& it)
                : m_it(it)
            {}

            // any_forward_iterator_interface<Reference> implementation
            virtual any_forward_iterator_wrapper* clone(
                typename any_forward_iterator_wrapper::buffer_type& buffer
                ) const
            {
                return new (buffer.allocate(sizeof(*this)))
                                any_forward_iterator_wrapper(m_it);
            }

            virtual any_forward_iterator_wrapper<
                        WrappedIterator
                      , typename any_forward_iterator_wrapper::const_reference
                      , Buffer
                    >* clone_const_ref(
                            typename any_forward_iterator_wrapper::buffer_type& buffer
                        ) const
            {
                typedef any_forward_iterator_wrapper<
                            WrappedIterator
                          , typename any_forward_iterator_wrapper::const_reference
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual any_forward_iterator_wrapper<
                        WrappedIterator
                      , typename any_forward_iterator_wrapper::reference_as_value_type
                      , Buffer
                    >* clone_reference_as_value(
                            typename any_forward_iterator_wrapper::buffer_type& buffer
                    ) const
            {
                typedef any_forward_iterator_wrapper<
                            WrappedIterator
                          , typename any_forward_iterator_wrapper::reference_as_value_type
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual void increment()
            {
                ++m_it;
            }

            virtual bool equal(const any_single_pass_iterator_interface<Reference, Buffer>& other) const
            {
                return m_it == lslboost::polymorphic_downcast<const any_forward_iterator_wrapper*>(&other)->m_it;
            }

            virtual Reference dereference() const
            {
                return *m_it;
            }
        private:
            WrappedIterator m_it;
        };

        template<
            class WrappedIterator
          , class Reference
          , class Buffer
        >
        class any_bidirectional_iterator_wrapper
            : public any_bidirectional_iterator_interface<
                        Reference
                      , Buffer
                    >
        {
            BOOST_RANGE_CONCEPT_ASSERT(( BidirectionalIteratorConcept<WrappedIterator> ));
        public:
            any_bidirectional_iterator_wrapper()
                : m_it()
            {
            }

            explicit any_bidirectional_iterator_wrapper(const WrappedIterator& it)
                : m_it(it)
            {
            }

            virtual any_bidirectional_iterator_wrapper* clone(
                typename any_bidirectional_iterator_wrapper::buffer_type& buffer
                ) const
            {
                return new (buffer.allocate(sizeof(*this)))
                            any_bidirectional_iterator_wrapper(*this);
            }

            virtual any_bidirectional_iterator_wrapper<
                        WrappedIterator
                      , typename any_bidirectional_iterator_wrapper::const_reference
                      , Buffer
                    >* clone_const_ref(
                           typename any_bidirectional_iterator_wrapper::buffer_type& buffer
                       ) const
            {
                typedef any_bidirectional_iterator_wrapper<
                            WrappedIterator
                          , typename any_bidirectional_iterator_wrapper::const_reference
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual any_bidirectional_iterator_wrapper<
                        WrappedIterator
                      , typename any_bidirectional_iterator_wrapper::reference_as_value_type
                      , Buffer
                    >* clone_reference_as_value(
                           typename any_bidirectional_iterator_wrapper::buffer_type& buffer
                       ) const
            {
                typedef any_bidirectional_iterator_wrapper<
                            WrappedIterator
                          , typename any_bidirectional_iterator_wrapper::reference_as_value_type
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual void increment()
            {
                ++m_it;
            }

            virtual void decrement()
            {
                --m_it;
            }

            virtual bool equal(const any_single_pass_iterator_interface<Reference, Buffer>& other) const
            {
                return m_it == lslboost::polymorphic_downcast<const any_bidirectional_iterator_wrapper*>(&other)->m_it;
            }

            virtual Reference dereference() const
            {
                return *m_it;
            }

        private:
            WrappedIterator m_it;
        };

        template<
            class WrappedIterator
          , class Reference
          , class Difference
          , class Buffer
        >
        class any_random_access_iterator_wrapper
            : public any_random_access_iterator_interface<
                            Reference
                          , Difference
                          , Buffer
                        >
        {
            BOOST_RANGE_CONCEPT_ASSERT(( RandomAccessIteratorConcept<WrappedIterator> ));
        public:
            typedef Difference difference_type;

            any_random_access_iterator_wrapper()
                : m_it()
            {
            }

            explicit any_random_access_iterator_wrapper(const WrappedIterator& other)
                : m_it(other)
            {
            }

            virtual any_random_access_iterator_wrapper* clone(
                    typename any_random_access_iterator_wrapper::buffer_type& buffer
                ) const
            {
                return new (buffer.allocate(sizeof(*this)))
                                any_random_access_iterator_wrapper(*this);
            }

            virtual any_random_access_iterator_wrapper<
                        WrappedIterator
                      , typename any_random_access_iterator_wrapper::const_reference
                      , Difference
                      , Buffer
                    >* clone_const_ref(
                           typename any_random_access_iterator_wrapper::buffer_type& buffer
                           ) const
            {
                typedef any_random_access_iterator_wrapper<
                            WrappedIterator
                          , typename any_random_access_iterator_wrapper::const_reference
                          , Difference
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual any_random_access_iterator_wrapper<
                        WrappedIterator
                      , typename any_random_access_iterator_wrapper::reference_as_value_type
                      , Difference
                      , Buffer
                    >* clone_reference_as_value(
                           typename any_random_access_iterator_wrapper::buffer_type& buffer
                           ) const
            {
                typedef any_random_access_iterator_wrapper<
                            WrappedIterator
                          , typename any_random_access_iterator_wrapper::reference_as_value_type
                          , Difference
                          , Buffer
                        > result_type;

                return new (buffer.allocate(sizeof(result_type)))
                            result_type(m_it);
            }

            virtual void increment()
            {
                ++m_it;
            }

            virtual bool equal(const any_single_pass_iterator_interface<Reference, Buffer>& other) const
            {
                return m_it == lslboost::polymorphic_downcast<const any_random_access_iterator_wrapper*>(&other)->m_it;
            }

            virtual void decrement()
            {
                --m_it;
            }

            virtual void advance(Difference offset)
            {
                m_it += offset;
            }

            virtual Reference dereference() const
            {
                return *m_it;
            }

            virtual Difference distance_to(const any_random_access_iterator_interface<Reference, Difference, Buffer>& other) const
            {
                return lslboost::polymorphic_downcast<const any_random_access_iterator_wrapper*>(&other)->m_it - m_it;
            }

        private:
            WrappedIterator m_it;
        };

        template<
            class WrappedIterator
          , class Traversal
          , class Reference
          , class Difference
          , class Buffer
        >
        struct any_iterator_wrapper_type_generator;

        template<
            class WrappedIterator
          , class Reference
          , class Difference
          , class Buffer
        >
        struct any_iterator_wrapper_type_generator<
            WrappedIterator
          , incrementable_traversal_tag
          , Reference
          , Difference
          , Buffer
        >
        {
            typedef any_incrementable_iterator_wrapper<
                        WrappedIterator
                      , Reference
                      , Buffer
                    > type;
        };

        template<
            class WrappedIterator
          , class Reference
          , class Difference
          , class Buffer
        >
        struct any_iterator_wrapper_type_generator<
            WrappedIterator
          , single_pass_traversal_tag
          , Reference
          , Difference
          , Buffer
        >
        {
            typedef any_single_pass_iterator_wrapper<
                        WrappedIterator
                      , Reference
                      , Buffer
                > type;
        };

        template<
            class WrappedIterator
          , class Reference
          , class Difference
          , class Buffer
        >
        struct any_iterator_wrapper_type_generator<
            WrappedIterator
          , forward_traversal_tag
          , Reference
          , Difference
          , Buffer
        >
        {
            typedef any_forward_iterator_wrapper<
                WrappedIterator
              , Reference
              , Buffer
            > type;
        };

        template<
            class WrappedIterator
          , class Reference
          , class Difference
          , class Buffer
        >
        struct any_iterator_wrapper_type_generator<
            WrappedIterator
          , bidirectional_traversal_tag
          , Reference
          , Difference
          , Buffer
        >
        {
            typedef any_bidirectional_iterator_wrapper<
                WrappedIterator
              , Reference
              , Buffer
            > type;
        };

        template<
            class WrappedIterator
          , class Reference
          , class Difference
          , class Buffer
        >
        struct any_iterator_wrapper_type_generator<
            WrappedIterator
          , random_access_traversal_tag
          , Reference
          , Difference
          , Buffer
        >
        {
            typedef any_random_access_iterator_wrapper<
                WrappedIterator
              , Reference
              , Difference
              , Buffer
            > type;
        };

    } // namespace range_detail
} // namespace lslboost

#endif // include guard