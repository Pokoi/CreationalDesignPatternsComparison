/*
 * File: DesignPatters.cpp
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

 ///////////////////////////////////////////////////
 //  STANDARD VERSION
#include <Forest.hpp>

 ///////////////////////////////////////////////////
//  ABSTRACT FACTORY VERSION
#include <AbstractFactoryForest.hpp>

///////////////////////////////////////////////////
//  BUILDER VERSION
#include <BuilderForest.hpp>

///////////////////////////////////////////////////
//  PROTOTYPE VERSION
#include <PrototypeForest.hpp>



#include <iostream>
#include <ctime>
#include <cstdlib>


Forest * forest;

const int number_of_trees   = 10000;
const int number_of_paths   = 100;
const int number_of_stones  = 20000;

void CreateForest();
void CreateForest(AbstractFactoryForest& factory);
void CreateForest(BuilderForest& builder);
void CreateForest(PrototypeForest& prototype);

int main()
{

    std::srand((float)time(NULL));

    // Standard Version
    CreateForest();

    // Abstract Factory
    AbstractFactoryForest abstract_factory;
    CreateForest(abstract_factory);


    // Builder Version
    BuilderForest builder;
    CreateForest(builder);

    // Prototype Version
    forest = new Forest;
    Tree* tree = new Tree;
    Stone* stone = new Stone;
    Path* path = new Path;

    PrototypeForest prototype(forest, stone, tree, path);
    CreateForest(prototype);

}

///////////////////////////////////////////////////
//  STANDARD VERSION

void CreateForest()
{
    
    forest = new Forest;

    for (size_t i = 0; i < number_of_trees; i++)
    {
        Tree* tree = new Tree();
        forest->add_tree(tree);
    }

    for (size_t i = 0; i < number_of_stones; i++)
    {
        Stone* stone = new Stone();
        forest->add_stone(stone);
    }

    for (size_t i = 0; i < number_of_paths; i++)
    {
        Path* path = new Path();
        forest->add_path(path);
    }
   
}



///////////////////////////////////////////////////
//  ABSTRACT FACTORY VERSION

void CreateForest(AbstractFactoryForest& factory)
{
    
    forest = factory.MakeForest();

    for (size_t i = 0; i < number_of_trees; i++)
    {
        Tree * tree = factory.MakeTree();
        forest->add_tree(tree);
    }

    for (size_t i = 0; i < number_of_stones; i++)
    {
        Stone* stone = factory.MakeStone();
        forest->add_stone(stone);
    }

    for (size_t i = 0; i < number_of_paths; i++)
    {
        Path* path = factory.MakePath();
        forest->add_path(path);
    }

}




///////////////////////////////////////////////////
//  BUILDER VERSION


void CreateForest(BuilderForest & builder)
{
    
    forest = builder.GetForest();

    for (size_t i = 0; i < number_of_trees; i++)
    {
        builder.BuildTree();
    }

    for (size_t i = 0; i < number_of_stones; i++)
    {
        builder.BuildStone();
    }

    for (size_t i = 0; i < number_of_paths; i++)
    {
        builder.BuildPath();
    }    

}




///////////////////////////////////////////////////
//  PROTOTYPE VERSION

void CreateForest(PrototypeForest& prototype)
{
    
    for (size_t i = 0; i < number_of_trees; i++)
    {
        Tree* tree = prototype.MakeTree();
        forest->add_tree(tree);
    }

    for (size_t i = 0; i < number_of_stones; i++)
    {
        Stone* stone = prototype.MakeStone();
        forest->add_stone(stone);
    }

    for (size_t i = 0; i < number_of_paths; i++)
    {
        Path* path = prototype.MakePath();
        forest->add_path(path);
    }

}

