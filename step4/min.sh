awk -F, '
    BEGIN {
        min = ""
    }
    {
        for (i = 1; i <= NF; i++) {
            if ($i ~ /^[0-9]+(\.[0-9]+)?$/) {  # Check if the field is a number
                if (min == "" || $i < min) min = $i
            }
        }
    }
    END {
        if (min == "") {
            print "No numeric values found"
        } else {
            print min
        }
    }
' rajan.csv

