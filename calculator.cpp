// Copyright (c) 2022 Alexander Matheson All rights reserved.

// Created by: Alexander Matheson
// Created on: Jan 23 2022
// This program uses a function to calculate
// either the surface area of a cube, the surface
// area of a rectangular prism or the volume of
// a cone (user's choice).
#include <cmath>
#include <iostream>


// calculate sa of cube
float CalcCube(float side) {
    // declare variable
    float saCube;
    saCube = 6 * pow(side, 2);
    return saCube;
}


// calculate sa of rectangular prism
float CalcPrism(float length, float width, float height) {
    // declare variable
    float saPrism;
    saPrism = 2 * (length * width + length * height + height * width);
    return saPrism;
}


// calculate volume of cone
float CalcCone(float radius, float height) {
    // declare variable
    float volumeCone;
    volumeCone = M_PI * pow(radius, 2) * height / 3;
    return volumeCone;
}


int main() {
    // declare variables
    std::string userChoice;
    std::string sideString;
    std::string lengthString;
    std::string widthString;
    std::string heightString;
    std::string radiusString;
    std::string heightStringCone;
    float sideInput;
    float lengthInput;
    float widthInput;
    float heightInput;
    float radiusInput;
    float heightInputCone;
    float answer;

    // get input
    std::cout << "What would you like to calculate?\n";
    std::cout << "Enter 1 for the surface area of a cube.\n";
    std::cout << "Enter 2 for the surface area of a rectangular prism\n";
    std::cout << "Enter 3 for the volume of a cone\n";
    std::cout << "Enter your choice: ";
    std::getline(std::cin, userChoice);

    // choose function
    // for cube
    if (userChoice == "1") {
        // get side length
        std::cout << "Enter the side length of the cube: ";
        std::getline(std::cin, sideString);
        // error checking
        try {
            sideInput = stof(sideString);
            // call function
            answer = CalcCube(sideInput);
            // display results
            std::cout << "The surface area is " << answer << " cm squared.";
        } catch (std::invalid_argument) {
            std::cout << "Invalid input.";
        }
    // for rectangular prism
    } else if (userChoice == "2") {
        // get width, length and height of rectangular prism
        std::cout << "Enter the length of the prism: ";
        std::getline(std::cin, lengthString);
        std::cout << "Enter the width of the prism: ";
        std::getline(std::cin, widthString);
        std::cout << "Enter the height of the cube: ";
        std::getline(std::cin, heightString);
        // error checking
        try {
            lengthInput = stof(lengthString);
            widthInput = stof(widthString);
            heightInput = stof(heightString);
            // call function
            answer = CalcPrism(lengthInput, widthInput, heightInput);
            // display results
            std::cout << "The surface area is " << answer << " cm squared.";
        } catch (std::invalid_argument) {
            std::cout << "Invalid input.";
        }
    // for cone
    } else if (userChoice == "3") {
        // get radius and height of cone
        std::cout << "Enter the radius of the cone: ";
        std::getline(std::cin, radiusString);
        std::cout << "Enter the height of the cone: ";
        std::getline(std::cin, heightStringCone);
        // error checking
        try {
            radiusInput = stof(radiusString);
            heightInputCone = stof(heightStringCone);
            // call function
            answer = CalcCone(radiusInput, heightInputCone);
            // display results
            std::cout << "The volume is " << answer << " cm cubed.";
        } catch (std::invalid_argument) {
            std::cout << "Invalid input.";
        }
    // for invalid input
    } else {
        std::cout << "Invalid input.";
    }
}
