// Compiler Interview Tasks
// Copyright (C) 2025 Dmitry Ryabtsev
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <optional>
#include <utility>
#include <queue>

class instr;

struct user_range final {
  instr *begin() const;
  instr *end() const;
};

struct instr {
  bool isMov() const;
  bool isLoad() const;
  user_range users();
};

// Design a function that takes an instruction that is guaranteed to not be
// a load, and finds the shortest def-use chain where the value of
// the instruction propagates through mov instructions and reaches a load
// instruction, so the chain should look like:
// given_inst -> mov -> mov -> ... -> mov -> mov -> load
// (shortest here means "containing the fewest instructions")
// If such chain exists, return the found load instruction and the number of
// mov instructions in-between, otherwise report that such chain doesn't exist.
//
// It's guaranteed that there are no loops.
std::optional<std::pair<instr &, int>> find_load_user(instr &root) {
  assert(!root.isLoad());
  // The current instruction, and how many movs are met so far (including
  // the current instruction).
  std::queue<std::pair<instr *, int>> q;
  // root doesn't contribute to the mov count.
  q.emplace(&root, 0);

  while (!q.empty()) {
    auto [cur_inst, cur_mov_count] = q.back();
    q.pop();
    assert(!cur_inst->isLoad());
    
    for (instr &user : cur_instr->users()) {
      if (user.isLoad())
        return std::pair<instr &, int>{user, cur_mov_count};
      if (user.isMov()) {
        q.emplace(&user, cur_mov_count + 1);
        continue;
      }
    }
  }
  return std::nullopt;
}

// Bonus task:
// Also return return the list of every instruction in the chain (maybe except
// the first one).

