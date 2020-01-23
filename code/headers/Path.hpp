/*
 * File: Path.hpp
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

class Path
{
    Vertex start;
    Vertex end;

    int width;
    int curves;

public:

    Path()
    {
        std::srand((int)time(NULL));
        
        this->width   = (rand() % 5) + 2;
        this->curves  = (rand() % 100) + 1;

        this->start   = Vertex();
        this->end     = Vertex();
    }

    void set_curves  (int curves    ) { this->curves    = curves;  }
    void set_width   (int width     ) { this->width     = width;   }
    void set_start   (Vertex start  ) { this->start     = start;   }
    void set_end     (Vertex end    ) { this->end       = end;     }

    int     get_curves  () { return curves;     }
    int     get_width   () { return width;      }
    Vertex  get_start   () { return start;      }
    Vertex  get_end     () { return end;        }

    Path * Copy()
    {
        Path * copy = new Path;
        
        copy->set_curves    (this->curves);
        copy->set_width     (this->width);
        copy->set_start     (this->start);
        copy->set_end       (this->end);

        return copy;
    }
};