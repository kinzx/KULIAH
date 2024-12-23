def calculator():
    print("Pilihan Operasi:")
    print("1. Tambah (+)")
    print("2. Kurang (-)")
    print("3. Kali (*)")
    print("4. Bagi (/)")

    choice = input("Pilih operasi (1/2/3/4): ")
    num1 = float(input("Masukkan angka pertama: "))
    num2 = float(input("Masukkan angka kedua: "))

    if choice == '1':
        print(f"Hasil: {num1 + num2}")
    elif choice == '2':
        print(f"Hasil: {num1 - num2}")
    elif choice == '3':
        print(f"Hasil: {num1 * num2}")
    elif choice == '4':
        if num2 != 0:
            print(f"Hasil: {num1 / num2}")
        else:
            print("Error: Tidak bisa membagi dengan 0!")
    else:
        print("Pilihan tidak valid!")

calculator()
