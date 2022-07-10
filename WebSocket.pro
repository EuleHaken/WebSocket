TEMPLATE = subdirs
SUBDIRS += src
CONFIG += ordered

CONFIG += c++20

!no_tests {
    SUBDIRS += tests
} else {
    message(Tests disabled)
}
