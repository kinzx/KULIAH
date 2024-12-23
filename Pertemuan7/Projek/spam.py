import pyautogui
import time

# Pesan yang ingin dikirim
pesan = "mana?"
jumlah_pesan = 10
jeda_detik = 0.1


time.sleep(5)

try:
    for i in range(jumlah_pesan):
        pyautogui.typewrite(pesan)  # Mengetik pesan di area chat
        pyautogui.press("enter")  # Mengirim pesan
        print(f"Pesan ke-{i + 1} berhasil dikirim!")
        time.sleep(jeda_detik)  # Jeda sebelum pesan berikutnya
except Exception as e:
    print("Terjadi kesalahan:", e)
