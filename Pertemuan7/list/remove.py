mammals = ["singa", "gajah", "harimau", "kuda", "kambing", "sapi"]
sea_animals = ["ikan paus", "hiu", "gurita", "ubur-ubur", "kepiting", "penyu"]
birds = ["ayam", "bebek", "angsa", "merpati", "elang", "burung beo"]
tropical_fruits = ["mangga", "pisang", "nanas", "durian", "pepaya", "rambutan"]
berries = ["strawberry", "blueberry", "raspberry", "blackberry", "cranberry", "mulberry"]

tropical_fruits.remove("pisang")
del berries[1]
mammals.clear()

print(f"\n{birds}\n{tropical_fruits}\n{berries}\n{mammals}")

