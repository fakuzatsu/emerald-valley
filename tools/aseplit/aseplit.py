import os
import subprocess
import sys
import platform

os_name = platform.system()

if os_name == "Linux":
    # Check if running inside WSL
    if "microsoft" in os.popen("uname -r").read().lower():
        ASEPRITE_PATH = r"/mnt/c/Program Files/Aseprite/aseprite.exe"  # WSL Path
    else:
        ASEPRITE_PATH = r"/usr/bin/aseprite"  # Native Linux path
elif os_name == "Windows":
    ASEPRITE_PATH = r"C:\Program Files\Aseprite\aseprite.exe"
elif os_name == "Darwin":
    ASEPRITE_PATH = r"/Applications/Aseprite.app/Contents/MacOS/aseprite"
else:
    print("Unknown OS")
    sys.exit(1)

def split_layers(directory):
    # Search for the .aseprite file inside the directory
    ase_file = None
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".ase"):
                ase_file = os.path.join(root, file)
                break
        if ase_file:
            break

    if not ase_file:
        print(f"No .aseprite file found in {directory}")
        return False

    print(f"Found .aseprite file: {ase_file}")
    
    # Run Aseprite to split layers
    try:
        subprocess.run([ASEPRITE_PATH, "-b", ase_file, "--save-as", os.path.join(directory, "{layer}.png")], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running Aseprite: {e}")
        return False

    # Check if layers were successfully exported (e.g., 'bottom.png' as a test file)
    if not os.path.exists(os.path.join(directory, "bottom.png")):
        print("Couldn't find the 'bottom.png' file. Make sure the layers in the .aseprite file are named correctly.")
        return False

    print(f"Layers exported successfully to {directory}/")
    return True

if __name__ == "__main__":
    # Check if directory was passed as argument
    if len(sys.argv) != 2:
        print("Usage: python split_layers.py [directory]")
        sys.exit(1)

    directory = sys.argv[1]
    
    if not os.path.isdir(directory):
        print(f"The path {directory} is not a valid directory.")
        sys.exit(1)
    
    if not split_layers(directory):
        sys.exit(1)
