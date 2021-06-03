import sys
from random import choice

first_names = ["Max", "Erika"]
last_names = ["Mustermann", "Musterfrau"]
streets = ["Musterstrasse", "Musterweg"]
numbers = ["1", "123", "42"]
postalCodes = ["12345", "54321"]
towns = ["Musterstadt", "Musterdorf"]

with open("addresses.txt", "w") as file:
    for _ in range(int(sys.argv[1] if len(sys.argv) >= 2 else 100)):
        file.writelines(" ".join(choice(seq) for seq in [first_names, last_names, streets, numbers, postalCodes, towns]) + "\n")
