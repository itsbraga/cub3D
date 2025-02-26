#!/bin/bash

TEXTURE_TYPES=("ceiling" "floor" "wall" "door")

for TYPE in "${TEXTURE_TYPES[@]}"; do
    SRC_DIR="./textures_png/$TYPE"
    DEST_DIR="../textures/$TYPE"

    mkdir -p "$DEST_DIR"

    for file in "$SRC_DIR"/*.png; do
        [ -e "$file" ] || continue
        filename=$(basename "$file" .png)
        convert "$file" "$DEST_DIR/${filename}.xpm"
        echo "Converti: $file -> $DEST_DIR/${filename}.xpm"
    done
done

echo "✅ Toutes les conversions sont terminées !"
