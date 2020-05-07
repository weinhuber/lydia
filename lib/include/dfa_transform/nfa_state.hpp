#pragma once
/*
 * This file is part of Lydia.
 *
 * Lydia is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Lydia is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Lydia.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "dfa.hpp"
#include "logic.hpp"
#include "types.hpp"
#include <memory>
#include <utility>
#include <utils/compare.hpp>

namespace whitemech {
namespace lydia {

/*!
 * This class represents an NFA state in
 * the LDLf2NFA algorithm presented in [1].
 * This will be used in tandem with the DFAState
 * of the algorithm LDLf2DFA [2].
 *
 * [1] Brafman, Ronen I., Giuseppe De Giacomo, and Fabio Patrizi.
 *     "LTLf/LDLf non-markovian rewards."
 *     Thirty-Second AAAI Conference on Artificial Intelligence. 2018.
 * [2] Favorito, Marco. "Reinforcement learning for LTLf/LDLf goals:
 *     Theory and implementation." Master's thesis. DIAG, Sapienza Univ. Rome
 *     (2018).
 */
class NFAState : public Basic {
public:
  const static TypeID type_code_id = TypeID::t_NFAState;
  const set_formulas formulas;
  explicit NFAState(set_formulas formulas);
  void accept(Visitor &v) const override{};
  hash_t compute_hash_() const override;
  int compare(const Basic &rhs) const override;
  bool is_equal(const Basic &rhs) const override;

  /*!
   * Check if the current state is final.
   *
   * As explained in (Brafman et al. 2018), it means to check
   * whether the conjunction of all the formulas in the current state,
   * after having applied the delta function with epsilon to each of them,
   * reduces to True.
   *
   * @return whether the NFA state is final.
   */
  bool is_final() const;

  /*!
   * Compute the next states, given a propositional interpretation.
   *
   * That is, compute the successors of each NFA state in the current DFA state.
   *
   * @param i the propositional interpretation (a set of propositional atoms).
   * @return the next NFA states.
   */
  set_nfa_states next_states(const set_atoms_ptr &i) const;
  std::vector<std::pair<set_atoms_ptr, set_nfa_states>>
  next_transitions() const;
};

} // namespace lydia
} // namespace whitemech