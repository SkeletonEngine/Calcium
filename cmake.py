import os
import platform

if platform.system() == "Windows":
  os.system("cmake -B build/Windows")
elif platform.system() == "Darwin":
  os.system("cmake -B build/macOS -G Xcode")
elif platform.system() == "Linux":
  os.system("cmake -B build/Linux/debug -DCMAKE_BUILD_TYPE=Debug")
  os.system("cmake -B build/Linux/release -DCMAKE_BUILD_TYPE=Release")
else:
  print("Operating system not supported!")

