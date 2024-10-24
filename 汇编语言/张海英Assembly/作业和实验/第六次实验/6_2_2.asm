.model small
.stack
.data
.code
.startup
.repeat
mov [bx], ax
inc bx
inc bx
inc ax
.until ax==10

.exit 0
end