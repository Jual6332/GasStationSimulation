#include <iostream>
#include <thread>
#include <unistd.h>
#include <chrono>

const int ARRAY_LENGTH = 10;

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

class GasPump {
  public:
    int numberOfFillups = 0;
};

/*
// Change this function to accept a Car object as an input parameter
void exec(int n){
  std::cout << "thread " << n << std::endl;
}
*/

void fillUpWithGas(Car *inputCar, GasPump *inputPump){
  std::this_thread::sleep_for(std::chrono::milliseconds(30));
  inputPump->numberOfFillups++;
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

  Car fifthCar;
  fifthCar.carID = 5;

  Car sixthCar;
  sixthCar.carID = 6;

  Car seventhCar;
  seventhCar.carID = 7;
  Car eigthCar;
  eigthCar.carID = 8;

  Car ninthCar;
  ninthCar.carID = 9;

  Car tenthCar;
  tenthCar.carID = 10;

  // Array to Store Car Object Data
  Car arrayOfCars[ARRAY_LENGTH];

  arrayOfCars[0] = firstCar;
  arrayOfCars[1] = secondCar;
  arrayOfCars[2] = thirdCar;
  arrayOfCars[3] = fourthCar;

  arrayOfCars[4] = fifthCar;
  arrayOfCars[5] = sixthCar;
  arrayOfCars[6] = seventhCar;
  arrayOfCars[7] = eigthCar;

  arrayOfCars[8] = ninthCar;
  arrayOfCars[9] = tenthCar;

  GasPump gasPump1;
  GasPump gasPump2;

  int totalNumberOfGasFillupsAllCars = 0;

  while (totalNumberOfGasFillupsAllCars < 1000){
    for (int i=0; i<10; i++){
      if (totalNumberOfGasFillupsAllCars % 2 == 0){
        fillUpWithGas(&arrayOfCars[i],&gasPump1);
      } else {
        fillUpWithGas(&arrayOfCars[i],&gasPump2);
      }
      //std::cout << arrayOfCars[i].numberOfFillups << std::endl;
      totalNumberOfGasFillupsAllCars++;
    }
  }

  // Print Total Number of Times that a Pump was used to fillup a Car with Gas
  std::cout << "Total # of gas fillups: " << totalNumberOfGasFillupsAllCars << std::endl;
  std::cout << "Total fillups at gasPump 1: " << gasPump1.numberOfFillups << std::endl;
  std::cout << "Total fillups at gasPump 2: " << gasPump2.numberOfFillups << std::endl;
  
  std::cout << "Project Finished!\n";
}