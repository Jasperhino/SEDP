#/bin/bash!
echo "./regex-filter hpi.de"
./regex-filter hpi.de

echo "./regex-filter student"
./regex-filter student

echo "student . hpi . uni-potsdam"
./regex-filter "student . hpi . uni-potsdam"

echo "student.hpi.uni-potsdam"
./regex-filter student.hpi.uni-potsdam

echo "(lu).*@hpi.de"
./regex-filter "(lu).*@hpi.de"

echo "lu.*@hpi.de"
./regex-filter "lu.*@hpi.de"

echo ".*lu.*@hpi.de"
./regex-filter ".*lu.*@hpi.de"

echo "([a-zA-Z0-9]+).*"
./regex-filter "([a-zA-Z0-9]+).*"
