#include <gtest/gtest.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    bool forsen = true;

    forsen ? void(qInfo() << "forsen is true") : void();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
