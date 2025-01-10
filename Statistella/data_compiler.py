
def compile(data_ptr, fill_mode) -> str:
    if fill_mode == 'mean':
        data_ptr.fillna(data_ptr.mean(), inplace=True)
    elif fill_mode == 'median':
        data_ptr.fillna(data_ptr.median(), inplace=True)
    elif fill_mode == 'mode':
        data_ptr.fillna(data_ptr.mode()[0], inplace=True).to_csv('train(mode_fill).csv', index=False)
    else:
        raise ValueError('Invalid fill mode')
    return "Successfully altered data."

