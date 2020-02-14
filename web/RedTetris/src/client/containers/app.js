import React from 'react'
import { connect } from 'react-redux'
import Tetris from '../components/Tetris/'

const App = () => {
  return (
    <Tetris />
  )
}

const mapStateToProps = state => {
  return {
    piece: state.piece,
  }
}

export default connect(mapStateToProps, null)(App)
