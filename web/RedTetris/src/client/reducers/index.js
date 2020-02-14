import { combineReducers } from 'redux';

import piece from './piecesReducer';
import map from './mapReducer';
import game from './gameReducer';

const rootReducer = combineReducers({
  piece,
  map,
  game,
});

export default rootReducer;
