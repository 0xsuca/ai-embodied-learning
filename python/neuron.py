class neuron:
    def __init__(self, threshold):
        self.threshold = threshold

    def determination(self, color: sensor, flat: sensor, deep: sensor):
        if (color + flat + deep) >= self.threshold:
            return True
        else:
            return False
class sensor:
    def __init__(self, weight: int, value: bool):
        self.weight = weight
        self.value = value
    def __effective(self) -> int:
        return self.weight if self.value else 0
    def __add__(self, other) -> int:
        if isinstance(other, sensor):
            return self.__effective() + other.__effective()
        return self.__effective() + other
    def __radd__(self,other: sensor) -> int:
        return self.__add__(other)


if __name__ == "__main__":
    color = sensor(1, True)
    flat = sensor(2, True)
    deep = sensor(3, True)

    neu = neuron(7)
    print(neu.determination(color,flat,deep))
