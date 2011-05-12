#!/usr/bin/env python

from distutils.core import setup, Extension

Module_module = Extension('_PieAlign',
			   sources=['PieAlign_wrap.cxx', 'Module.cpp', 'AlignedSequence.cpp', 'Alignment.cpp', 'Node.cpp', 'Parser.cpp', 'Scoring.cpp', 'Sequence.cpp', 'Tree.cpp', 'Writer.cpp'],
			  )

setup (name = 'PieAlign',
       version = '0.1',
       author = "Anthony Do",
       description = "Linked",
       ext_modules = [Module_module],
       py_modules = ["PieAlign"],
       )
