## @file setup.py

## @brief	sets up the correct flags for SWIG

## @author	Tony Do,
#			Dane Elshof,
#			Jonathan Nicholson,
#			Dan Thode

## @date	11. May 2011


from distutils.core import setup, Extension

Module_module = Extension('_PieAlign',
			   sources=['PieAlign_wrap.cxx', 'Module.cpp', 'AlignedSequence.cpp', 'Alignment.cpp', 'Node.cpp', 'Parser.cpp', 'Scoring.cpp', 'Sequence.cpp', 'Tree.cpp', 'Writer.cpp', 'Direction.cpp', 'Tub.cpp'],
			  )

setup (name = 'PieAlign',
       version = '0.1',
       author = "Anthony Do",
       description = "Linked",
       ext_modules = [Module_module],
       py_modules = ["PieAlign"],
       )
