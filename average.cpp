// Copyright (c) 2019 Joseph Palermo All rights reserved.
//
// Created by: Joseph Palermo
// Created on: December 2019
// This program calculates the average of an array of numbers

#include <iostream>
#include <ctime>

template <int rows, int cols>
float calculate(float(&arrayOfNumbers)[rows][cols]) {
    // this function calculates the average of all numbers in a 2D array

    // variables
    float sum = 0;
    float averageDivider = 0;
    float numberAverage;

    // process
    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement) {
            sum = sum + arrayOfNumbers[rowElement][columnElement];
            averageDivider += 1;
        }
    }

    numberAverage = sum/averageDivider;
    return numberAverage;
}


int main() {
    // This function generates random numbers then prints the average

    // variables
    float randomNumber;
    const int rows = 3;
    const int columns = 2;
    float numberArray[rows][columns];
    float average;

    // seed
    unsigned int seed = time(NULL);

    // process
    for (int rowElement = 0; rowElement < rows; rowElement++) {
        std::cout << "Row " << rowElement + 1 << ":" << std::endl;
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            randomNumber = rand_r(&seed) % 50;
            numberArray[rowElement][columnElement] = randomNumber;
            std::cout << randomNumber << std::endl;
        }
        std::cout << "" << std::endl;
    }

    average = calculate(numberArray);

    // output
    std::cout << "The sum of all the numbers is: " << average;
}
