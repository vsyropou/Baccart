cards = ['Aspd', '2spd', '3spd', '4spd', '5spd', '6spd', '7spd', '8spd', '9spd', '10spd', 'Jspd', 'Qspd', 'Kspd', 'Adim', '2dim', '3dim', '4dim', '5dim', '6dim', '7dim', '8dim', '9dim', '10dim', 'Jdim', 'Qdim', 'Kdim', 'Ahrt', '2hrt', '3hrt', '4hrt', '5hrt', '6hrt', '7hrt', '8hrt', '9hrt', '10hrt', 'Jhrt', 'Qhrt', 'Khrt', 'Aclb', '2clb', '3clb', '4clb', '5clb', '6clb', '7clb', '8clb', '9clb', '10clb', 'Jclb', 'Qclb', 'Kclb', 'Aspd', '2spd', '3spd', '4spd', '5spd', '6spd', '7spd', '8spd', '9spd', '10spd', 'Jspd', 'Qspd', 'Kspd', 'Adim', '2dim', '3dim', '4dim', '5dim', '6dim', '7dim', '8dim', '9dim', '10dim', 'Jdim', 'Qdim', 'Kdim', 'Ahrt', '2hrt', '3hrt', '4hrt', '5hrt', '6hrt', '7hrt', '8hrt', '9hrt', '10hrt', 'Jhrt', 'Qhrt', 'Khrt', 'Aclb', '2clb', '3clb', '4clb', '5clb', '6clb', '7clb', '8clb', '9clb', '10clb', 'Jclb', 'Qclb', 'Kclb']


num_decks = 2
flag = len(set(cards)) == len(cards) / num_decks

print '%s cads are in the deck'%('All' if flag else 'Not all')
