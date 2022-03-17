#include <iostream>
#include <thread>
#include <unistd.h>
#include <chrono>

const int ARRAY_LENGTH = 9;

class Car {
  public:
    int carID = 0;
    int numberOfFillups = 0;
  
  void printCarID(){
    std::cout << "This is car "<< carID << "." << std::endl;
  }

  void printNumberOfFillups(){
    std::cout << numberOfFillups << std::endl;
  }
};

/*
// Change this function to accept a Car object as an input parameter
void exec(int n){
  std::cout << "thread " << n << std::endl;
}
*/

void fillUpWithGas(Car *inputCar){
  std::this_thread::sleep_for(std::chrono::milliseconds(30));
  inputCar->numberOfFillups++;
}
  
int main() {
  // Initialize All Cars for GasPump Simulation
  Car firstCar;
  firstCar.carID = 1;
  Car secondCar;
  secondCar.carID = 2;
  Car thirdCar;
  thirdCar.carID = 3;
  Car fourthCar;
  fourthCar.carID = 4;

  Car arrayOfCars[ARRAY_LENGTH];

  arrayOfCars[0] = firstCar;
  arrayOfCars[1] = secondCar;
  arrayOfCars[2] = thirdCar;
  arrayOfCars[3] = fourthCar;

  int totalGasFillupsAllCars = 0;

  for (int i=0; i<4; i++){
    fillUpWithGas(&arrayOfCars[i]);
    std::cout << arrayOfCars[i].numberOfFillups << std::endl;
    totalGasFillupsAllCars++;
  }

  std::cout << "Total # of gas fillups: " << totalGasFillupsAllCars << std::endl;

  //std::thread(exec,0);
  
  std::cout << "Hello World!\n";
}