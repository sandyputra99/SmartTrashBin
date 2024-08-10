#mengimport modul tkinter
import Tkinter as tk
#Membuat object tkinter
root = tk.Tk()
#Membuat widget label
w = tk.Label root, text=("Hello Tkinter!")
#Memasang widget
w.pack() 
#Menjalankan program
root.mainloop()
