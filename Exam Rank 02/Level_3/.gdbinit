set print pretty on
set print array on

define ft_atoi
	display sign
	display res
	display str
	display str[i]
end

define is_prime
	display check
	display n
end

define put_nbr
	display n
	display digit
end

define main
	display ac
	display av
	display *av@ac
	display **av
end

#start gdb at main
break main
run ""
main
info break

