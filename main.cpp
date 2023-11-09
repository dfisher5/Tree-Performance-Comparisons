/**
 * Delaney Fisher
 * CS 124
 * Section A
 */

#include "Spotify.h"
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "SplayTree.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <cstdlib>

using namespace std;

int main() {
    /**
     * Binary Search Trees Section
     */
    // Add values to tree
    BinarySearchTree<int> bst1;
    for (int i = 1; i <= 100; i++) {
        bst1.add(i);
    }

    // Open output file and add header
    fstream fOut1;
    fOut1.open("data/inOrderTree.csv", ios::out);
    fOut1 << "value,depth" << "\n";

    // Gets value and depth
    vector<int> inOrderTreeDepths;
    for (int i = 1; i <= 100; i++) {
        int depth = 0;
        bst1.find(i, depth);
        fOut1 << i << "," << depth << "\n";
        inOrderTreeDepths.push_back(depth);
    }

    fOut1.close();
    bst1.timber();

    // Add values to tree
    BinarySearchTree<int> bst2;
    vector<int> randomValues;
    for (int i = 1; i <= 100; i++) {
        randomValues.push_back(i);
    }
    randomValues.pop_back();

    // Shuffle vector then add values to tree
    random_device rd;
    shuffle(randomValues.begin(), randomValues.end(), rd);
    for (int i = 0; i <= randomValues.size(); i++){
        bst2.add(randomValues[i]);
    }

    // Open output file and add header
    fstream fOut2;
    fOut2.open("data/shuffledTree.csv", ios::out);
    fOut2 << "value,depth" << "\n";

    // Gets value and depth
    for (int i = 1; i <= 100; i++) {
        int depth = 0;
        bst2.find(i, depth);
        fOut2 << i << "," << depth << "\n";
    }

    fOut2.close();
    bst2.timber();

    // Create a Spotify object which allows the load from file function to be called
    // Load songs from csv file into a vector
    vector<Spotify> songs;
    string fn = "data/spotify_data_final.csv";
    Spotify spotObject = *new Spotify();
    spotObject.loadFromFile(fn, songs);

    // Add songs to tree
    BinarySearchTree<Spotify> bst3;
    for (int i = 0; i < songs.size(); i++) {
        bst3.add(songs[i]);
    }

    // Open output file and add header
    fstream fOut3;
    fOut3.open("data/spotifyTree.csv", ios::out);
    fOut3 << "value,depth,song position" << "\n";

    // Gets value and depth
    for (int i = 0; i < songs.size(); i++) {
        int depth = 0;
        bst3.find(songs[i], depth);
        fOut3 << songs[i] << "," << depth << "," << i+1 << "\n";
    }

    fOut3.close();
    bst3.timber();


    /**
     * AVL Trees Section
     */
    // Add values to the tree
    AvlTree<int> avl1;
    for (int i = 1; i <= 100; i++) {
        avl1.add(i);
    }

    // Open output file and add header
    fstream fOut4;
    fOut4.open("data/inOrderAVLTree.csv", ios::out);
    fOut4 << "value,depth" << "\n";

    // Gets value and depth
    for (int i = 1; i <= 100; i++) {
        int depth = 0;
        avl1.find(i, depth);
        fOut4 << i << "," << depth << "\n";
    }

    fOut4.close();
    avl1.timber();

    // Add values to the tree
    AvlTree<int> avl2;
    for (int i = 0; i <= randomValues.size(); i++){
        avl2.add(randomValues[i]);
    }

    // Open output file and add header
    fstream fOut5;
    fOut5.open("data/shuffledAVLTree.csv", ios::out);
    fOut5 << "value,depth" << "\n";

    // Gets value and depth
    for (int i = 1; i <= 100; i++) {
        int depth = 0;
        avl2.find(i, depth);
        fOut5 << i << "," << depth << "\n";
    }

    fOut5.close();
    avl2.timber();

    // Add values to the tree
    AvlTree<Spotify> avl3;
    for (int i = 0; i < songs.size(); i++) {
        avl3.add(songs[i]);
    }

    // Open output file and add header
    fstream fOut6;
    fOut6.open("data/spotifyAVLTree.csv", ios::out);
    fOut6 << "value,depth,song position" << "\n";

    // Gets value and depth
    for (int i = 0; i < songs.size(); i++) {
        int depth = 0;
        avl3.find(songs[i], depth);
        fOut6 << songs[i] << "," << depth << "," << i+1 << "\n";
    }

    fOut6.close();
    avl3.timber();


    /**
     * Splay Trees Section
     */
    // Add values to the tree
    SplayTree<int> splay1(false);
    for (int i = 1; i <= 100; i++) {
        splay1.add(i);
    }

    // Open output file and add header
    fstream fOut7;
    fOut7.open("data/inOrderSplayTree.csv", ios::out);
    fOut7 << "value,depth" << "\n";

    // Gets value and depth
    for (int i = 1; i <= 100; i++) {
        int depth = 0;
        splay1.find(i, depth);
        fOut7 << i << "," << depth << "\n";
    }

    fOut7.close();
    splay1.timber();

    // Add values to the tree
    SplayTree<int> splay2(false);
    for (int i = 0; i <= randomValues.size(); i++){
        splay2.add(randomValues[i]);
    }

    // Open output file and add header
    fstream fOut8;
    fOut8.open("data/shuffledSplayTree.csv", ios::out);
    fOut8 << "value,depth" << "\n";

    // Gets value and depth
    for (int i = 1; i <= 100; i++) {
        int depth = 0;
        splay2.find(i, depth);
        fOut8 << i << "," << depth << "\n";
    }

    fOut8.close();
    splay2.timber();

    // Add values to the tree
    SplayTree<Spotify> splay3(false);
    for (int i = 0; i < songs.size(); i++) {
        splay3.add(songs[i]);
    }

    // Open output file and add header
    fstream fOut9;
    fOut9.open("data/spotifySplayTree.csv", ios::out);
    fOut9 << "value,depth,song position" << "\n";

    // Gets value and depth
    for (int i = 0; i < songs.size(); i++) {
        int depth = 0;
        splay3.find(songs[i], depth);
        fOut9 << songs[i] << "," << depth << "," << i+1 << "\n";
    }

    fOut9.close();
    splay3.timber();


    /**
     * Call to Python file using CLI
     */
    if (getenv("windir") == NULL) {
        system("python3 ../Graphing.py");
    }
    else {
        system("py ../Graphing.py");
    }

    return 0;
}