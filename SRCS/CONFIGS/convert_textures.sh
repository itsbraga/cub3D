#!/bin/bash

TEXTURE_TYPES=("CEILING" "FLOOR" "WALL" "DOOR")

for TYPE in "${TEXTURE_TYPES[@]}"; do
    SRC_DIR="./TEXTURES_PNG/$TYPE"
    DEST_DIR="../TEXTURES/$TYPE"

    mkdir -p "$DEST_DIR"

    for file in "$SRC_DIR"/*.png; do
        [ -e "$file" ] || continue
        filename=$(basename "$file" .png)
        convert "$file" "$DEST_DIR/${filename}.xpm"
        echo "Converti: $file -> $DEST_DIR/${filename}.xpm"
    done
done

echo "✅ Toutes les conversions sont terminées !"
