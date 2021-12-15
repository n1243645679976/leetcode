class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.q = [0, big, medium, small]

    def addCar(self, carType: int) -> bool:
        self.q[carType] -= 1
        return self.q[carType] > -1
