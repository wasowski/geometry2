#!/usr/bin/env python

# Witness for a bug in main, it appears easier to write in python (so there is
# no linking problems with more than one main function in the same executable,
# when using gtest)

PKG = 'test_tf4_ros'
# import roslib; roslib.load_manifest(PKG)  # This line is not needed with Catkin.

import sys
import unittest
from subprocess import call

class BugWitness(unittest.TestCase):

    def test_1(self):
        # TODO: invoke static_transform_publisher.cpp::main here with 
        # 9 arguments to cause a crash 
        self.assertTrue(False)


if __name__ == '__main__':
    import rosunit
    rosunit.unitrun(PKG, 'bug_witness', BugWitness)
