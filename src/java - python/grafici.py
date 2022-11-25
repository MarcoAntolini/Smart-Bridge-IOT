# libraries
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

  # data
df = pd.DataFrame({
      'x_axis': range(1,10),
      'y_axis': np.random.randn(9)*80+range(1,10)
  })

  # plot
plt.plot('x_axis', 'y_axis', data=df, linestyle='-', marker='o')
plt.show()