/*
 * File: Tree.hpp
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

#include <Utils.hpp>

class Tree
{
    int height;
    int width;

    Vertex * vertices;

public:

    Tree()
    {
        std::srand((int)time(NULL));

        this->height    = (rand() % 20) + 5;
        this->width     = (rand() % 10) + 1;
        this->vertices  = new Vertex[1000];
    }

    ~Tree()
    {
        delete[] vertices;
    }

    void set_height     (int height       ) { this->height = height;     }
    void set_width      (int width        ) { this->width = width;       }
    void set_vertices   (Vertex * vertices) { this->vertices = vertices; }

    int     get_height  ()      { return height;    }
    int     get_width   ()      { return width;     }
    Vertex* get_vertices()      { return vertices;  }

    Tree * Copy()
    {
        Tree* copy = new Tree;

        copy->set_height    (this->height);
        copy->set_width     (this->width);
        copy->set_vertices  (this->vertices);

        return copy;
    }
};