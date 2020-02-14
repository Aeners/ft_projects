import { connect } from 'react-redux';
import Tetris from './Tetris';

import { startTheGame } from '../../actions/gameActions';

const mapStateToProps = state => {
  return {
    gameHasStarted: state.game.gameHasStarted,
    gameIsFinished: state.game.gameIsFinished,
  };
};

const mapDispatchToProps = dispatch => {
  return {
    startTheGame: () => {
      dispatch(startTheGame());
    },
  };
};

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(Tetris);
