/*
 * File: PrototypeForest.hpp
 * File Created: 23th January 2020
 * ––––––––––––––––––––––––
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * ––––––––––––––––––––––––
 * MIT License
 *
 * Copyright (c) 2020 Pokoidev
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <Path.hpp>
#include <Stone.hpp>
#include <Tree.hpp>
#include <Forest.hpp>

class PrototypeForest
{
private:
    Forest  * prototype_forest;
    Stone   * prototype_stone;
    Tree    * prototype_tree;
    Path    * prototype_path;

public:

    PrototypeForest(Forest* forest, Stone* stone, Tree* tree, Path* path)
    {
        prototype_forest    = forest;
        prototype_stone     = stone;
        prototype_tree      = tree;
        prototype_path      = path;
    }

    virtual Forest* MakeForest() const { return prototype_forest->Copy(); }
    virtual Stone * MakeStone () const { return prototype_stone ->Copy(); }
    virtual Tree  * MakeTree  () const { return prototype_tree  ->Copy(); }
    virtual Path  * MakePath  () const { return prototype_path  ->Copy(); }
};