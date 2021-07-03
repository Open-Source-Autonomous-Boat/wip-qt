#!/bin/bash

QSB_BIN=""
GLSL_VER="440,460,100"
MSL_VER=12
HLSL_VER=51

check_qsb_loc() {
        qsb_bin_res=$(
                find /usr/ -regextype sed -regex ".*qsb" 2> /dev/null |
                sed "/\.qsb/d"
        )
        QSB_BIN=$(echo $qsb_bin_res | tr " " "\n" | cut -d " " -f1)
}

compile_shaders() {
        if ! [ -d "." ]
        then
                echo "Please go to project root then exeucte this script"
                exit
        fi
        shader_files=$(find . -regextype sed -regex ".*\(frag\|vert\)"
        )
        echo $shader_files | tr " " "\n" | while read file
        do
                $QSB_BIN -b --glsl "$GLSL_VER" --hlsl $HLSL_VER --msl $MSL_VER -o "$file.qsb" "$file"
                echo "$QSB_BIN -b --glsl "$GLSL_VER" --hlsl $HLSL_VER --msl $MSL_VER -o '$file.qsb' '$file'"
        done
}


main() {
        if ! command -v qsb &> /dev/null
        then
                echo "Failed to find qsb"
                echo "Trying to find qsb location"
                check_qsb_loc
        else
                QSB_BIN=$(command -v qsb)
                echo "qsb found $qsb_bin"
        fi
        compile_shaders
}


main
