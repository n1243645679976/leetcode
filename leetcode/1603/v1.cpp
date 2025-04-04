class ParkingSystem {
public:
    vector<int> q;
    ParkingSystem(int big, int medium, int small) {
        q = {0, big, medium, small};
    }
    
    bool addCar(int carType) {
        return --q[carType] >= 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */