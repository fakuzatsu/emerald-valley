import os
import subprocess
import sys

# Define the path to Aseprite executable here (adjust the path as needed for your system)
ASEPRITE_PATH = r"/mnt/c/Program Files/Aseprite/aseprite.exe"  # For WSL (default Windows path)
# For macOS or Linux, you might use something like:
# ASEPRITE_PATH = "/usr/local/bin/aseprite"

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
