# Copyright (C) 2019 Free Software Foundation, Inc.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.

if [ x${LD_FLAG} = x ]
then
cat << EOF

OUTPUT_FORMAT("elf32-sun32")
ENTRY (_start)
OUTPUT_ARCH("sun32")

SECTIONS
{
.text :	{
	.= ALIGN(4)
	*(.text)
	*(text)
	${RELOCATING+ _start = .;}
	}
}
EOF
