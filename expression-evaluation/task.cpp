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

class Expr {
public:
    virtual int eval() const;
};

class Const : public Expr {
    const int Val = 0;
};

class Binary : public Expr {
protected:
    const Expr *LHS;
    const Expr *RHS;
};

class Plus : public Binary {
};

class Minus : public Binary {
};

// Expression: 1 + 2 - 3
// Becomes:
// Minus{Plus{Const{1}, Const{2}}, Const{3}}

// Implement expression evaluation.
int evaluate(const Expr &E);
