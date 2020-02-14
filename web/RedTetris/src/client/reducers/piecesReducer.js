import * as ActionTypes from '../actionTypes/piecesActionTypes';

const initialState = {
  block: [[0, 1, 0, 0], [0, 1, 0, 0], [0, 1, 0, 0], [0, 1, 0, 0]],
  position: {
    x: 0,
    y: 0,
  },
};

const piece = (state = initialState, { type }) => {
  switch (type) {
    case ActionTypes.PIECE_GO_DOWN:
      return {
        ...state,
        position: {
          ...state.position,
          y: state.position.y + 1,
        },
      };
    case ActionTypes.PIECE_GO_RIGHT:
      return {
        ...state,
        position: {
          ...state.position,
          x: state.position.x + 1,
        },
      };
    case ActionTypes.PIECE_GO_LEFT:
      return {
        ...state,
        position: {
          ...state.position,
          x: state.position.x - 1,
        },
      };
    default:
      return state;
  }
};

export default piece;
