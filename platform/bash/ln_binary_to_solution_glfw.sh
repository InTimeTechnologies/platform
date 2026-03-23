# Arguments
BUILD_DIR=$1

# Does BUILD_DIR has a value
if [[ -z "$BUILD_DIR" ]]; then
    echo "Error: BUILD_DIR not passed."
    echo "Aborting script."
    return 1
fi

# Is BUILD_DIR a valid directory path
if [ -d "$DIR" ]; then
else
  echo "Error: BUILD_DIR=$BUILD_DIR does not exist."
  echo "Aborting script."
  return 2
fi

echo "BUILD_DIR=$BUILD_DIR"
echo "creating glfw symbolic links to solution's glfw .so files."
ln -s "../../../../dependencies/glfw/build/lib/libglfw.so.3.5" "$BUILD_DIR/libglfw.so.3"
ln -s "../../../../dependencies/glfw/build/lib/libglfw.so.3.5" "$BUILD_DIR/libglfw.so"
