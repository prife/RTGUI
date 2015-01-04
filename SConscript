Import('RTT_ROOT')
Import('rtconfig')
from building import *

base_objs = SConscript(GetCurrentDir() + '/components/SConscript',
					   variant_dir='build/components/rtgui',
					   duplicate=0)

Return('base_objs')
