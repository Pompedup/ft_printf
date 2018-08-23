
void	lltoa(t_printf *dt, t_flags *dt_flags, intmax_t nbr)
{
	get_len(dt_flags, nbr < 0 ? -nbr : nbr);
	apply_flags(dt_flags, nbr < 0, TRUE, nbr);
	if (!(dt_flags->flags & MINUS))
		padding(dt, dt_flags, FALSE);
	if (dt_flags->c)
	{
		rotative_buf(dt, &dt_flags->c, 1);
		dt_flags->len--;
	}
	padding(dt, dt_flags, TRUE);
	dt->buf_move += dt_flags->len - 1;
	dt->less -= dt_flags->len - 1;
	if (dt_flags->len)
		addnbr(dt->buf_move, nbr < 0 ? -nbr : nbr, HEXAMIN, 10);
	dt->buf_move++;
	dt->less--;
	if (dt_flags->flags & MINUS)
		padding(dt, dt_flags, FALSE);
}

void	ulltoa(t_printf *dt, t_flags *dt_flags, uintmax_t nbr)
{
	get_len(dt_flags, nbr);
	apply_flags(dt_flags, FALSE, FALSE, nbr);
	if (!(dt_flags->flags & MINUS))
		padding(dt, dt_flags, FALSE);
	if (dt_flags->hash)
	{
		rotative_buf(dt, dt_flags->hash, );
		dt_flags->len -= ft_strlen(dt_flags->hash);
	}
	padding(dt, dt_flags, TRUE);
	dt->buf_move += dt_flags->len - 1;
	dt->less -= dt_flags->len - 1;
	if (dt_flags->len)
		addnbr(dt->buf_move, nbr, *dt->format == 'X'
			? HEXAMAX : HEXAMIN, dt_flags->base);
	dt->buf_move++;
	dt->less--;
	if (dt_flags->flags & MINUS)
		padding(dt, dt_flags, FALSE);
}
