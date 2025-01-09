def convert_time_seconds(time_str):
    minutes, seconds = map(int, time_str.split(':'))
    return minutes * 60 + seconds

def convert_time(seconds):
    minutes = seconds // 60
    seconds = seconds % 60
    return f'{minutes:02d}:{seconds:02d}'


def solution(video_len, pos, op_start, op_end, commands):
    video_len = convert_time_seconds(video_len)
    pos = convert_time_seconds(pos)
    op_start = convert_time_seconds(op_start)
    op_end = convert_time_seconds(op_end)
    
    def opening_check(pos):
        # 오프닝 체크 함수
        if op_start <= pos <=op_end:
            return op_end
        else:
            return pos
            
    pos = opening_check(pos)
    
    for command in commands:
        if command == 'prev':
            # 오프닝 일 경우
            pos = opening_check(max(0, pos-10))
        elif command == 'next':
            # 끝났을 경우
            pos = opening_check(min(video_len, pos+10))


    return convert_time(pos)