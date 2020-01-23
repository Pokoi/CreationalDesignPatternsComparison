/*
 * File: Stone.hpp
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

class Stone
{

    int weight;
    int size;

    Vertex * vertices;

public:

    Stone()
    {
        std::srand((int)time(NULL));

        this->weight    = (rand() % 10) + 1;
        this->size      = (rand() % 10) + 1;
        this->vertices  = new Vertex[500];
    }

    ~Stone()
    {
        delete[] vertices;
    }
     
    void set_weight  (int weight      ) { this->weight = weight;     }
    void set_size    (int size        ) { this->size = size;         }
    void set_vertices(Vertex* vertices) { this->vertices = vertices; }

    int     get_weight  () { return weight;     }
    int     get_size    () { return size;       }
    Vertex* get_vertices() { return vertices;   }

    Stone * Copy()
    {
        Stone* copy = new Stone;

        copy->set_weight    (this->weight);
        copy->set_size      (this->size);
        copy->set_vertices  (this->vertices);

        return copy;
    }

};