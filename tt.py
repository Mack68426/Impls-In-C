

def decode(text: str):
    table = {}
    for ch in (65, 97):
        for i in range(26):
            table[chr(ch + i)] = chr( (i - 3)%26 + ch)
    
    return ''.join([table.get(c,c) for c in text])



