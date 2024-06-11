BEGIN {
    print "NAME", "\t", "SUB-1", "\t", "SUB-2", "\t", "SUB-3", "\t", "SUB-4", "\t", "SUB-5", "\t", "SUB-6", "\t", "STATUS";
    print"___________________________________________________________________________\n";
}

{
    # BODY
    if ( $2 < 45 || $3 < 45 || $4 < 45 || $5 < 45 || $6 < 45 || $7 < 45 ) {
        print $1, "\t", $2, "\t", $3, "\t", $4, "\t", $5, "\t", $6, "\t", $7, "\t", "FAIL";
    } else {
        print $1, "\t", $2, "\t", $3, "\t", $4, "\t", $5, "\t", $6, "\t", $7, "\t", "PASS";
    }
}

END {
    print"___________________________________________________________________________\n";
}
