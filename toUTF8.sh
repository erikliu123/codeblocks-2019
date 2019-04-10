 for JAVA_FILE in $(find -name "*.cpp")
    do
        if [ "$(file $JAVA_FILE | grep -v UTF-8)" != "" ] ;then
            echo convert $JAVA_FILE
            iconv -f GBK -t UTF-8 $JAVA_FILE > $JAVA_FILE
        fi
    done
