// -*- C++ -*-

// Copyright (C) 2005, 2006 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the terms
// of the GNU General Public License as published by the Free Software
// Foundation; either version 2, or (at your option) any later
// version.

// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
// MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free
// software library without restriction.  Specifically, if other files
// instantiate templates or use macros or inline functions from this
// file, or you compile this file and link it with other files to
// produce an executable, this file does not by itself cause the
// resulting executable to be covered by the GNU General Public
// License.  This exception does not however invalidate any other
// reasons why the executable file might be covered by the GNU General
// Public License.

// Copyright (C) 2004 Ami Tavory and Vladimir Dreizin, IBM-HRL.

// Permission to use, copy, modify, sell, and distribute this software
// is hereby granted without fee, provided that the above copyright
// notice appears in all copies, and that both that copyright notice
// and this permission notice appear in supporting documentation. None
// of the above authors, nor IBM Haifa Research Laboratories, make any
// representation about the suitability of this software for any
// purpose. It is provided "as is" without express or implied
// warranty.

/**
 * @file node_base.hpp
 * Contains a pat_trie_node_base base for a patricia tree.
 */

#ifndef PB_DS_PAT_TRIE_NODE_BASE_HPP
#define PB_DS_PAT_TRIE_NODE_BASE_HPP

#include <ext/pb_ds/detail/pat_trie_/node_metadata_base.hpp>

namespace pb_ds
{
  namespace detail
  {
#define PB_DS_CLASS_T_DEC \
    template<typename Type_Traits, typename E_Access_Traits,	\
	     typename Metadata,	typename Allocator>

#define PB_DS_CLASS_C_DEC \
    pat_trie_node_base<Type_Traits, E_Access_Traits, Metadata, Allocator>

#define PB_DS_PAT_TRIE_SUBTREE_DEBUG_INFO_C_DEC	\
    pat_trie_subtree_debug_info<Type_Traits, E_Access_Traits, Allocator>

    enum pat_trie_node_type
      {
	pat_trie_internal_node_type,
	pat_trie_leaf_node_type,
	pat_trie_head_node_type
      };

    template<typename Type_Traits,
	     typename E_Access_Traits,
	     typename Metadata,
	     typename Allocator>
    struct pat_trie_node_base : public pat_trie_node_metadata_base<
      Metadata,
      Allocator>
    {
    public:
      typedef
      typename Allocator::template rebind<
      pat_trie_node_base>::other::pointer
      node_pointer;

      typedef
      typename Allocator::template rebind<
	E_Access_Traits>::other::const_pointer
      const_e_access_traits_pointer;

#ifdef _GLIBCXX_DEBUG
      typedef
      std::pair<
	typename E_Access_Traits::const_iterator,
	typename E_Access_Traits::const_iterator>
      subtree_debug_info;
#endif 

      pat_trie_node_base(pat_trie_node_type type);

#ifdef _GLIBCXX_DEBUG
      void
      assert_valid(const_e_access_traits_pointer p_traits) const;

      virtual subtree_debug_info
      assert_valid_imp(const_e_access_traits_pointer p_traits) const = 0;
#endif 

      node_pointer m_p_parent;
      const pat_trie_node_type m_type;
    };

    PB_DS_CLASS_T_DEC
    PB_DS_CLASS_C_DEC::
    pat_trie_node_base(pat_trie_node_type type) : m_type(type)
    { }

#ifdef _GLIBCXX_DEBUG
    PB_DS_CLASS_T_DEC
    void
    PB_DS_CLASS_C_DEC::
    assert_valid(const_e_access_traits_pointer p_traits) const
    { assert_valid_imp(p_traits); }
#endif 

#undef PB_DS_CLASS_T_DEC
#undef PB_DS_CLASS_C_DEC
#undef PB_DS_PAT_TRIE_SUBTREE_DEBUG_INFO_C_DEC

  } // namespace detail
} // namespace pb_ds

#endif