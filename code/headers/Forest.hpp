/*
 * File: Forest.hpp
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
#include <list>

class Forest
{
    std::list<Tree>     trees;
    std::list<Stone>    stones;
    std::list<Path>     paths;

public:

    Forest() {}

    void add_tree   (Tree   * tree  ) { this->trees.push_back(*tree);   }
    void add_stone  (Stone  * stone ) { this->stones.push_back(*stone); }
    void add_path   (Path   * path  ) { this->paths.push_back(*path);   }

    void set_trees  (std::list<Tree> trees  ) { this->trees = trees;    }
    void set_stones (std::list<Stone> stones) { this->stones = stones;  }
    void set_path   (std::list<Path> paths  ) { this->paths = paths;    }

    std::list<Tree>     get_tree () { return this->trees;   }
    std::list<Stone>    get_stone() { return this->stones;  }
    std::list<Path>     get_path () { return this->paths;   }

    Forest * Copy()
    {
        Forest* copy = new Forest;

        copy->set_trees (this->trees);
        copy->set_stones(this->stones);
        copy->set_path  (this->paths);

        return copy;
    }

};